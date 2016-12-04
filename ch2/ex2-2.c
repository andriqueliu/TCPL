


// write a loop equivalent to OG for loop without using && and ||

for (i = 0; i < lim-1; && (c=getchar()) != '\n' && c!= EOF;++i) {
    s[i] = c;
}

// DONE...

// doesn't specify for or while...
// also lets you use breaks! (or at least doesn't restrict them)
// OG idea: while plus a few ifs
//
int i = 0;
while (i < (lim - 1)) {
    if ((c = getchar() != '\n')) {
        if (c != EOF) {
            s[i] = c;
            ++i;
        }
    }
}
