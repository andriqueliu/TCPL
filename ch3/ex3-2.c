#include  <stdio.h>

void escape(char *s, char *t);

int main() /* count digits, white space, others */
{
    /*
    int c, i, nwhite, nother, ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
            nwhite, nother);
    */
    
    char text1[50] = "hello    \t it is me.\n"; // buffer size!!!
    char text2[50];
    
    char text3[50] = "so yeah it \\t is me";
    char text4[50] = ;

    printf("%s\n", text1);

    escape(text2, text1);
    
    printf("%s\n", text2);

    return 0;
}

// copy from string t to s... change newlines and tabs into \n and \t
void escape(char *s, char *t) {
    int i = 0; 
    int k = 0;

    while (t[i] != EOF) { // is this the same as (t[i]) ??? ... it is!
        switch(t[i]) {
        case '\n':
            s[k] = '\\';
            s[k + 1] = 'n'; // note: you're going one place ahead to make room for n or t
            k++;
            break;
        case '\t':
            s[k] = '\\';
            s[k + 1] = 't';
            k++;
            break;
        default:
            s[k] = t[i];
            break;
        }
        i++; // this is to iterate both positions
        k++;
    }
    
}

// now convert escape characters into the real characters
// let's go from t to s just for simplicity 
void unescape(char *s, char *t) {
    int i = 0;
    int k = 0;

    while (t[i] != EOF) {
        

        switch(t[i]) {
        case '\\': // use nested cases!!!

            switch(t + i)
        }

    }
}
