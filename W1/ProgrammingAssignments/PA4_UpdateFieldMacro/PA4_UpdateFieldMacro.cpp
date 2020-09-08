#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <sstream>

using namespace std;

#define UPDATE_FIELD(ticket, field, values) \
\
if (values.count(#field)==1) {                 \
istringstream is(values.at(#field));             \
is >> ticket.field;                             \
}

bool operator==(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.year, lhs.month, lhs.day} ==
        vector<int>{rhs.year, rhs.month, rhs.day};
}

bool operator==(const Time& lhs, const Time& rhs) {
    return vector<int>{lhs.hours, lhs.minutes} ==
        vector<int>{rhs.hours, rhs.minutes};
}

istream& operator>>(istream& is, Date& date) {
    int year;
    bool streamStatus = true;

    is >> year;

    streamStatus = streamStatus && is && (is.peek() == '-');
    is.ignore(1);

    if (!streamStatus) {
        throw logic_error("Wrong date format: ");
    }

    int month;
    is >> month;
    streamStatus = streamStatus && is && (is.peek() == '-');
    is.ignore(1);

    if (!streamStatus) {
        throw logic_error("Wrong date format: ");
    }

    int day;
    is >> day;
    streamStatus = streamStatus && is;

    if (!streamStatus) {
        throw logic_error("Wrong date format: ");
    }

    date.day = day;
    date.month = month;
    date.year = year;

    return is;
}

istream& operator>>(istream& is, Time& time) {
    int hours;
    bool streamStatus = true;

    is >> hours;

    streamStatus = streamStatus && is && (is.peek() == ':');
    is.ignore(1);

    if (!streamStatus) {
        throw logic_error("Wrong date format: ");
    }

    int minutes;
    is >> minutes;
    streamStatus = streamStatus && is;

    if (!streamStatus) {
        throw logic_error("Wrong date format: ");
    }

    time.hours = hours;
    time.minutes = minutes;

    return is;
}
bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.year, lhs.month, lhs.day} <
        vector<int>{rhs.year, rhs.month, rhs.day};
}

bool operator<(const Time& lhs, const Time& rhs) {
    return vector<int>{lhs.hours, lhs.minutes} <
        vector<int>{rhs.hours, rhs.minutes};
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.year <<
        "-" << setw(2) << setfill('0') << date.month <<
        "-" << setw(2) << setfill('0') << date.day;
    return os;
}

ostream& operator<<(ostream& os, const Time& time) {
    os << setw(2) << setfill('0') << time.hours <<
        "-" << setw(2) << setfill('0') << time.minutes;
    return os;
}

                                           

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
      {"departure_date", "2018-2-28"},
      {"departure_time", "17:40"},
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
      {"price", "12550"},
      {"arrival_time", "20:33"},
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
    // значения этих полей не должны измениться
    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{ 20, 33 }));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}
