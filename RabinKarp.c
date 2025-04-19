#include <stdio.h>
#include <string.h>
#define d 256 // Number of characters in input alphabet 
void rabinKarp(char *text, char *pattern, int q)
{
	int N = strlen(text);
	int M = strlen(pattern);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for text
	int h = 1;
	int found = 0;
// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;
// Calculate hash value for pattern and first window of text
	for (i = 0; i < M; i++) 
    {
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
	}

// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) 
    {
		// If hash values match, check characters one by one
		if (p == t) 
        {
			for (j = 0; j < M; j++) 
            {
				if (text[i + j] != pattern[j])
					break;
			}
			if (j == M) {
				printf("Pattern found at index %d\n", i);
				found = 1;
			}
		}

		// Calculate hash for next window
		if (i < N - M) {
			t = (d * (t - text[i] * h) + text[i + M]) % q;
			if (t < 0)
				t += q;
		}
	}

	if (!found)
		printf("Pattern not found in the text.\n");
}

int main()
{
	char text[1000], pattern[100];

	printf("Enter the main string: ");
	fgets(text, sizeof(text), stdin);
	text[strcspn(text, "\n")] = 0;
	printf("Enter the pattern to search: ");
	fgets(pattern, sizeof(pattern), stdin);
	pattern[strcspn(pattern, "\n")] = 0;
	int q = 101; // A prime number
	rabinKarp(text, pattern, q);
	return 0;
}