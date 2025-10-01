// 계정 옮기는 프로젝트
// https://github.com/Jonatha1209/FastIO/blob/main/main.cpp

#include <unistd.h>
#include <string>
using namespace std;
#define ll long long
constexpr int SZ = 32768;
char read_buf[SZ]; int read_idx = 0, read_len = 0;
char write_buf[SZ]; int write_idx = 0;

inline char read_char() {
    if (read_idx == read_len) {
        read_len = fread(read_buf, 1, SZ, stdin);
        if (!read_len) return 0;
        read_idx = 0;
    }
    return read_buf[read_idx++];
}

template<typename T>
inline void read_int(T& x) {
    char c; x = 0; bool neg = 0;
    while ((c = read_char()) && (c < '0' || c > '9') && c != '-');
    if (c == '-') neg = 1, c = read_char();
    do x = x * 10 + (c - '0');
    while ((c = read_char()) && c >= '0' && c <= '9');
    if (neg) x = -x;
}

inline void read_str(string& s) {
    char c;
    s.clear();
    while ((c = read_char()) != 0 && (c == ' ' || c == '\n' || c == '\r'));
    if (c == 0) return; 

    do {
        s += c;
        c = read_char();
    } while (c != 0 && c != ' ' && c != '\n' && c != '\r');
}



inline void read_line(string &s) {
    s.clear();
    char c;
    while ((c = read_char()) && (c == '\n' || c == '\r'));
    
    if (c == 0) return;
    do {
        s += c;
        c = read_char();
    } while (c != 0 && c != '\n' && c != '\r');
}


inline void write_char(char c) {
    if (write_idx == SZ) {
        fwrite(write_buf, 1, SZ, stdout);
        write_idx = 0;
    }
    write_buf[write_idx++] = c;
}

template<typename T>
inline void write_int(T x) {
    if (x < 0) write_char('-'), x = -x;
    char s[20]; ll idx = 0;
    do s[idx++] = x % 10 + '0'; while (x /= 10);
    while (idx--) write_char(s[idx]);
}

inline void write_str(const char* s) {
    while (*s) write_char(*s++);
}

inline void write_ln() {
    write_char('\n');
}

inline void read_double(double &x) {
    char c;
    bool neg = false;
    x = 0;
    while ((c = read_char()) && c != '-' && (c < '0' || c > '9'));
    if (c == '-') neg = true, c = read_char();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = read_char();
    }
    if (c == '.') {
        double frac = 1;
        c = read_char();
        while (c >= '0' && c <= '9') {
            frac /= 10;
            x += (c - '0') * frac;
            c = read_char();
        }
    }
    if (neg) x = -x;
}

inline void write_double(double x, int precision = 9) {
    if (x < 0) {
        write_char('-');
        x = -x;
    }
    ll int_part = x;
    write_int(int_part);
    x -= int_part;
    write_char('.');
    for (int i = 0; i < precision; ++i) {
        x *= 10;
        int digit = x;
        write_char('0' + digit);
        x -= digit;
    }
}

inline bool read_int_safe(ll &x) {
    char c; x = 0; bool neg = 0;
    while ((c = read_char()) && (c < '0' || c > '9') && c != '-') {
        if (c == 0) return false;
    }
    if (c == 0) return false;
    if (c == '-') neg = 1, c = read_char();
    do {
        if (c == 0) break;
        x = x * 10 + (c - '0');
    } while ((c = read_char()) && c >= '0' && c <= '9');
    if (neg) x = -x;
    return true;
}


void flush() {
    fwrite(write_buf, 1, write_idx, stdout);
    write_idx = 0;
}
