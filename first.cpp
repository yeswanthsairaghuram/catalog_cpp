#include <bits/stdc++.h>
using namespace std;

// Convert number string in given base to decimal
long long baseToDecimal(const string &val, int base) {
    long long result = 0;
    for (char c : val) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else digit = tolower(c) - 'a' + 10;
        result = result * base + digit;
    }
    return result;
}

// Lagrange interpolation at x=0 to get constant term
long double lagrangeAtZero(const vector<pair<long long, long double>> &points) {
    long double secret = 0.0;
    int k = points.size();
    for (int i = 0; i < k; i++) {
        long double xi = points[i].first;
        long double yi = points[i].second;
        long double term = yi;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                long double xj = points[j].first;
                term *= (-xj) / (xi - xj);
            }
        }
        secret += term;
    }
    return secret;
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    vector<pair<long long, long double>> points;
    cout << "Enter each point as: x base value\n";
    for (int i = 0; i < n; i++) {
        long long x;
        int base;
        string val;
        cin >> x >> base >> val;
        long long y = baseToDecimal(val, base);
        if (i < k) { // only store first k points
            points.push_back({x, (long double)y});
        }
    }

    long double secret = lagrangeAtZero(points);

    cout << "Secret (C) = " << fixed << setprecision(0) << secret << endl;
    return 0;
}
