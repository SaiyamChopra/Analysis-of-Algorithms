#include <stdio.h> 
#include <string.h> 
void computeLPSArray(char* pattern, int M, int* lps) { 
int length = 0; 
lps[0] = 0;
int i = 1; 
while (i < M) { 
    if (pattern[i] == pattern[length]) { 
        length++; 
        lps[i] = length; 
        i++; 
    } else { 
        if (length != 0) { 
            length = lps[length - 1]; 
        } else { 
            lps[i] = 0; 
            i++; 
        } 
    } 
} 
} 

void KMPSearch(char* pattern, char* text) { 
int M = strlen(pattern); 
int N = strlen(text); 

int lps[M]; 
computeLPSArray(pattern, M, lps); 

int i = 0; // index for text 
int j = 0; // index for pattern 
int found = 0; 

while (i < N) { 
    if (pattern[j] == text[i]) { 
        i++; 
        j++; 
    } 

    if (j == M) { 
        printf("Pattern found at index %d\n", i - j); 
        found = 1; 
        j = lps[j - 1]; 
    } else if (i < N && pattern[j] != text[i]) { 
        if (j != 0) 
            j = lps[j - 1]; 
        else 
            i++; 
    } 
} 

if (!found) 
    printf("Pattern not found in the text.\n"); 
} 

int main() { 
char text[1000], pattern[100]; 

printf("Enter the main string: "); 
fgets(text, sizeof(text), stdin); 
text[strcspn(text, "\n")] = 0; // Remove newline 

printf("Enter the pattern to search: "); 
fgets(pattern, sizeof(pattern), stdin); 
pattern[strcspn(pattern, "\n")] = 0; // Remove newline 

KMPSearch(pattern, text); 
return 0; 
} 