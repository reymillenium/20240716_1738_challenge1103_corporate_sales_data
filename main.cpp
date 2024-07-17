/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                       *
 *   Name: Reinier Garcia Ramos                                                          *
 *                                                                                       *
 *   Program Title: Corporate Sales Data                                                 *
 *                                                                                       *
 *   Purpose:                                                                            *
 *   Receives from the user all the quarter sales for all the four existing divisions    *
 *   (East, West, North & South) and then renders on the terminal per Division the       *
 *   Total AnnualSales  and the averageQuarterlySales.                                   *
 *                                                                                       *
 *   More Details:                                                                       *
 *   https://github.com/reymillenium/20240716_1738_challenge1103_corporate_sales_data    *
 *                                                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <sstream>
#include <vector>
#include <regex>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::string;
using std::to_string;
using std::stringstream;
using std::vector;
using std::regex;
using std::regex_match;
using std::stod;
using std::map;


// UTILITY FUNCTIONS PROTOTYPES


// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &input);

// Determines if a given string is a valid floating point number, using a regular expression
bool isFloatingPoint(const string &input);

// Receives and validates a double number (or the equivalent of an integer) from the console
double getDouble(const string &, double, double, bool = false, const string & = "Invalid input. Please try again.", const vector<double> & = {});

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(unsigned long long int);

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(long double, int = 2);

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(long double, int = 2, bool = true, const string & = "$");

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(long long int);

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double templateSumOfDoublesInArray(double (&)[N]);

template<int N>
double templateAverageAmongDoublesInArray(double (&)[N]);

enum DivisionName { East, West, North, South };

std::map<DivisionName, string> DIVISION_NAME_MAPPER = {
    {East, "East"},
    {West, "West"},
    {North, "North"},
    {South, "South"}
};


struct Division {
    DivisionName eDivisionName;
    double quarterlySales[4] {0.0, 0.0, 0.0, 0.0};


    [[nodiscard]] double totalAnnualSales() {
        return templateSumOfDoublesInArray(quarterlySales);
    }

    [[nodiscard]] double averageQuarterlySales() {
        return templateAverageAmongDoublesInArray(quarterlySales);
    }

    [[nodiscard]] string name() const {
        return DIVISION_NAME_MAPPER[eDivisionName];
    }
};


// CUSTOM MADE FUNCTIONS PROTOTYPES


// Initializes the existing divisions with just the eName, returning it
vector<Division> basicDivisionsInitializer();

// Gets from the user all the sales of all the quarters and for all the divisions
void getDivisionsQuarterSales(vector<Division> &);

// Displays all the results to the user
void displayResults(vector<Division> divisions);


// Main Function
int main() {
    vector<Division> divisions; // All the divisions

    // Basic initialization with all the four existing divisions
    divisions = basicDivisionsInitializer();

    // Gets from the user all the sales of all the quarters and for all the divisions
    getDivisionsQuarterSales(divisions);

    // Displays all the results to the user
    displayResults(divisions);

    return 0;
}


// UTILITY FUNCTIONS DEFINITIONS


// Determines if a given string is a valid integer, using a regular expression
bool isInteger(const string &input) {
    const regex pattern("^[+-]?[0-9]+$");
    return regex_match(input, pattern);
}

// Determines if a given string is a valid floating point number, using a regular expression
bool isFloatingPoint(const string &input) {
    const regex pattern(R"(^[+-]?[0-9]+(.[0-9]+)?([eE][+-]?[0-9]+)?$)");
    return regex_match(input, pattern);
}

// Receives and validates a double number (or the equivalent of an integer) from the console
double getDouble(const string &message, const double minValue, const double maxValue, const bool showRange, const string &errorMessage, const vector<double> &sentinelValues) {
    string numberAsString; // Value typed by the user, that can be a valid (integer or floating point) number or not
    double number = 0; // Double convertion (if possible) of the value typed by the user
    bool keepAsking = true; // If we must keep asking for a value to the user, until receiving either an integer or a flating point number

    do {
        cout << fixed << setprecision(2) << message;
        if (showRange)
            cout << " (" << minValue << " - " << maxValue << ")";
        cout << ": ";
        getline(cin, numberAsString);

        if (const bool isIntegerOrFloatingPointNumber = isInteger(numberAsString) || isFloatingPoint(numberAsString); !isIntegerOrFloatingPointNumber) {
            cout << "That's not an integer number nor a valid floating point number. Try again." << endl;
            continue; // There is no point in keep validating any further, as it's not even a valid integer nor a floating point number
        }

        number = stod(numberAsString); // When we reach this point, that means we have either a proper integer or a floating point number
        const bool invalidInput = number < minValue || maxValue < number; // If the input is valid, based only in minimum & maximum possible values
        // If the typed number is not among the given sentinel values (breaking values)
        const bool numberIsNotSentinel = count(sentinelValues.begin(), sentinelValues.end(), number) == 0;
        keepAsking = invalidInput && numberIsNotSentinel;
        if (keepAsking) cout << errorMessage << endl;
    } while (keepAsking);

    return number;
}

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(const unsigned long long int integerValue) {
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > 0; j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<unsigned long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the "0" & the dot ("."). Ex: 0.34 (the "0" must be removed next)
    return humanizeUnsignedInteger(integerValue) + decimalsAsString.substr(1, precision + 1);
}

// Formats a given double by inserting a comma every 3 digits of its equivalent string, to make it more readable, and adds a customizable currency symbol
string monetizeDouble(const long double doubleValue, const int precision, const bool prepend, const string &symbol) {
    return static_cast<string>(prepend ? (symbol + " ") : "") + humanizeUnsignedDouble(doubleValue, precision) + static_cast<string>(prepend ? "" : " " + symbol);
}

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(const long long int number) {
    const long long int lastDigit = number % 10;
    string additive = "th";

    switch (number) {
        case 11:
        case 12:
        case 13:
            break;
        default:
            switch (lastDigit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
                default: ;
            }
    }

    return to_string(number) + additive;
}

// Calculates the sum of all the elements inside an array of doubles
template<int N>
double templateSumOfDoublesInArray(double (&doublesArray)[N]) {
    double sum = 0.0;
    for (auto number: doublesArray) {
        sum += number;
    }
    return sum;
}

// Calculates the average among all the numbers inside an array of doubles
template<int N>
double templateAverageAmongDoublesInArray(double (&doublesArray)[N]) {
    const int length = sizeof(doublesArray) / sizeof(doublesArray[0]);
    return templateSumOfDoublesInArray(doublesArray) / length;
}


// CUSTOM MADE FUNCTIONS DEFINITIONS


// Initializes the existing divisions with just the eName, returning it
vector<Division> basicDivisionsInitializer() {
    return {
        Division {.eDivisionName = East},
        Division {.eDivisionName = West},
        Division {.eDivisionName = North},
        Division {.eDivisionName = South}
    };
}

// Gets from the user all the sales of all the quarters and for all the divisions
void getDivisionsQuarterSales(vector<Division> &divisions) {
    cout << endl;
    for (Division &division: divisions) {
        const int length = std::size(division.quarterlySales);
        for (int i = 0; i < length; i++) {
            division.quarterlySales[i] = getDouble("Type the " + ordinalFromNumber(i + 1) + " quarter sales amount, of the " + division.name() + " division please", 0, LONG_MAX);
        }
    }
}

// Displays all the results to the user
void displayResults(vector<Division> divisions) {
    cout << endl;
    for (Division division: divisions) {
        cout << "The " << division.name() << " division had an Annual Total Sales of " << monetizeDouble(division.totalAnnualSales());
        cout << " and an Average Quarterly Sales of " << monetizeDouble(division.averageQuarterlySales()) << endl;
    }
}
