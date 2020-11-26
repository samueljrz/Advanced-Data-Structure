#ifndef CONTROLL_H
#define CONTROLL_H

#include <bits/stdc++.h>

using std::vector;
using std::string;

vector<string> split( const string& str, const string& delim ) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
    	pos = str.find( delim, prev );
        if ( pos == string::npos ) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if ( !token.empty() ) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while ( pos < str.length() && prev < str.length() );
    return tokens;
}

int dataToInt( string data ) {
    int ans=0;
    vector<string> ret;
    ret = split( data, "/" );
    if( ret.size() == 3 ) {
        ans = stoi( ret[1] ) + stoi( ret[0] )*30 + stoi ( ret[2] )*365;
    }
    return ans;
}

#endif