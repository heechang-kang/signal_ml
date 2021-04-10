#include <bits/stdc++.h>
using namespace std;

#define B ((size_t)24000000)
char buf[1000000000];

int main(int argc, char **argv) {
    setbuf(stdout, NULL);
    if(strcmp(argv[1], "-s") == 0) {
        FILE *f = fopen(argv[2], "rb");
        size_t sz = fread(buf, 1, sizeof buf, f);
        fclose(f);
        for(int i = 0; B * i < sz; i++) {
            string cname = (string(argv[2]) + "." + to_string(i));
            f = fopen(cname.c_str(), "wb");
            size_t csz = min(sz - B * i, B);
            fwrite(buf + B * i, 1, csz, f);
            fclose(f);
        }
    } else if(strcmp(argv[1], "-m") == 0) {
        FILE *f;
        size_t sz = 0;
        for(int i=0; ; i++) {
            string cname = (string(argv[2]) + "." + to_string(i));
            f = fopen(cname.c_str(), "rb");
            if(f == NULL) break;
            size_t csz = fread(buf + sz, 1, sizeof buf, f);
            sz += csz;
            fclose(f);
        }
        f = fopen(argv[2], "wb");
        fwrite(buf, 1, sz, f);
        fclose(f);
    }
    return 0;
}
