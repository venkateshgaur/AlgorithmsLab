                                                                                                                              3                                                                                                       #include<stdio.h>
#include<stdlib.h>
#include<string.h>

void de(int n) {
    printf("\n%d", n);
}

void pa(int* a, int n) {
    printf("\n");
    for(int i = 0; i< n; i++) {
        printf("%d ",a[i]);
    }
}

int* getBSShiftTable(char *pattern, int m) {
    int *table = (int*) malloc(sizeof(int) * 128);
    for(int j = 0; j < 128; j++)
        table[j] = m;
    for(int i = m-2; i >= 0; i--) {
        if(table[pattern[i]] == m)
            table[pattern[i]] = m - i - 1;
    }
    return table;
}

int* getGSShiftTable(char* pattern, int m) {
    int* table = (int*) malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++) {
        table[i] = m;
    }

    de(1);

    int a,b,c,d,e;
    int k = 1;
    while(k < m) {

    de(2);
        a = k;
        b = 0;
        c = 1;
        d = 1;
        int f = 0;
        while(!f && m-d-k >= 0) //condition to ensure initial strMatch doesnt go under bounds
        {

    de(3);
            if(m-d-k-1 >= 0 && pattern[m-d-k-1] == pattern[m-k-1]) {
                d++;
                continue;
            }


            if(pattern[m-d-1] == pattern[m-1]) {
    de(4);  
                e = 1;
                while(e < k && pattern[m-d-e-1] == pattern[m-e-1]) {
    de(5);
                    e++;
                }
                if(e == k) {
    de(6);
                    f++;
                    break;
                }
            }
            d++;
        }

        if(f) {
            table[k] = d;
            k++;
            continue;
        }
        else {
            a = k-1;
            while(a > 0) {
                b = m-a;
                c = 0;
                int d = 0;

                while(d < a && pattern[b + d] == pattern[d]) {
                    d++;
                }

                if(d == a) {
                    table[k] = m - a;
                    break;
                }

                a--;
            }
        }
        k++;
    }
    return table;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int boyerMoore(char* text, int n, char* pattern, int m, int* bsTable, int* gsTable)
{
    de(88);
    int comps = 0;
    int shifts = 0;
    int i = m-1;
    int ind = -1;
    while(i <= n-1) {
    de(99);
        int k = 0;
        while(k < m && (++comps) && pattern[m-1-k] == text[i-k]) {
            k++;
        }
        if(k == 0) {
            shifts++;
            int d1 = bsTable[text[i-k]];
            d1 = max(d1-k, 1);
            i += d1;
        }
        else if(k == m) {
            return i-m+1;
        }
        else
        {
            shifts++;
            int d1 = bsTable[text[i-k]];
            d1 = max(d1-k, 1);
            int d2 = gsTable[k];
            i += max(d1, d2);
        }
    }
    return -1;

}

void main() {
    char t[100];
    char p[100];
    char buffer;

    printf("Enter the text: ");
    scanf("%[^\n]",t);
    scanf("%c", &buffer);
    printf("Enter the pattern: ");
    scanf("%[^\n]",p);

    int n = strlen(t);
    int m = strlen(p);

    int* bsTable = getBSShiftTable(p, m);
    int* gsTable = getGSShiftTable(p, m);

    pa(bsTable, 128);
    pa(gsTable, m);

    de(777);

    int resultInd = boyerMoore(t, n, p, m, bsTable, gsTable);

    if(resultInd < 0) {
        printf("Pattern not found in text");
    }
    else {
        printf("Pattern found in text at index %d", resultInd);
    }
    return;
}
