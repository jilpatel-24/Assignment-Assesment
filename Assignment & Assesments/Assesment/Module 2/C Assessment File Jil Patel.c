#include <stdio.h>
#include <string.h>

reverseString(char str[]) // Function to reverse a string
{
    int left = 0, right = strlen(str) - 1;
    while (left < right) 
	{
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

palindrome(char str[]) // Function to check if a string is a palindrome
{
    int length = strlen(str);
    int flag = 0;
    int i;
    for (i=0;i<length/2;i++) 
	{
        if (str[i] != str[length - i - 1]) 
		{
            flag = 1;
            break;
        }
    }
    if (flag == 1) 
	{
        printf("\nThis string is not a Palindrome");
    } 
	else 
	{
        printf("\nThis string is a Palindrome");
    }
}

findCharFrequency(char str[], char item) // Function to find frequency of a character in a string
{
    int length = strlen(str);
    int count = 0;
    int i;
    for (i=0;i<length;i++) 
	{
        if (item == str[i]) 
		{
            count++;
        }
    }
    printf("\nFrequency of '%c' is: %d", item, count);
}

findVowelsConsonants(char str[]) // Function to count vowels and consonants
{
    int length = strlen(str);
    int nv = 0, nc = 0;
    char vov[] = "aeiouAEIOU"; // Both lowercase and uppercase vowels
	int i;
    for (i=0;i<length;i++) 
	{
        if (strchr(vov, str[i]) != NULL) 
		{
            nv++;
        } 
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
		{
            nc++;
        }
    }

    printf("\nNumber of Vowels: %d", nv);
    printf("\nNumber of Consonants: %d", nc);
}

findBlankSpacesDigits(char str[]) // Function to count blank spaces and digits
{
    int length = strlen(str);
    int spacecount = 0, digitcount = 0;
    int i;
    for (i=0;i<length;i++) 
	{
        if (str[i] == ' ') 
		{
            spacecount++;
        }
        if (str[i] >= '0' && str[i] <= '9') 
		{
            digitcount++;
        }
    }
    printf("\nNumber of blank spaces: %d", spacecount);
    printf("\nNumber of digits: %d", digitcount);
}

main() 
{
    int exid = 1;
    int selid;
    char str[100], str21[100], str22[100], str3[100], str41[100], str42[100];
    char str5[100], str6[100], item6, str7[100], str8[100];

    while (exid == 1) 
	{
        printf("\n\nMain Menu\n");
        printf("\t1. Reverse a string\n");
        printf("\t2. Concatenation\n");
        printf("\t3. Palindrome\n");
        printf("\t4. Copy a string\n");
        printf("\t5. Length of the string\n");
        printf("\t6. Frequency of character in a string\n");
        printf("\t7. Find number of vowels and consonants\n");
        printf("\t8. Find number of blank spaces and digits\n");
        printf("\t9.Continue or Not\n");

        printf("\nSelect an Option: ");
        scanf("%d", &selid);
        getchar(); // To consume the newline character after entering selid

        switch (selid) {
            case 1: // Reverse a string
                printf("\nEnter a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0; // Remove newline character
                reverseString(str);
                printf("\nReversed string is: %s", str);
                break;
            case 2: // Concatenation
                printf("\nEnter first string: ");
                fgets(str21, sizeof(str21), stdin);
                str21[strcspn(str21, "\n")] = 0;
                printf("\nEnter second string: ");
                fgets(str22, sizeof(str22), stdin);
                str22[strcspn(str22, "\n")] = 0;
                strcat(str21, str22);
                printf("\nConcatenated string is: %s", str21);
                break;
            case 3: // Palindrome
                printf("\nEnter a string: ");
                fgets(str3, sizeof(str3), stdin);
                str3[strcspn(str3, "\n")] = 0;
                palindrome(str3);
                break;
            case 4: // Copy a string
                printf("\nEnter a string: ");
                fgets(str41, sizeof(str41), stdin);
                str41[strcspn(str41, "\n")] = 0;
                strcpy(str42, str41);
                printf("\nCopied string: %s", str42);
                break;
            case 5: // Length of the string
                printf("\nEnter a string: ");
                fgets(str5, sizeof(str5), stdin);
                str5[strcspn(str5, "\n")] = 0;
                printf("\nLength of the string is: %lu", strlen(str5));
                break;
            case 6: // Frequency of character in a string
                printf("\nEnter a string: ");
                fgets(str6, sizeof(str6), stdin);
                str6[strcspn(str6, "\n")] = 0;
                printf("\nEnter a character: ");
                scanf(" %c", &item6);
                findCharFrequency(str6, item6);
                break;
            case 7: // Find number of vowels and consonants
                printf("\nEnter a string: ");
                fgets(str7, sizeof(str7), stdin);
                str7[strcspn(str7, "\n")] = 0;
                findVowelsConsonants(str7);
                break;
            case 8: // Find number of blank spaces and digits
                printf("\nEnter a string: ");
                fgets(str8, sizeof(str8), stdin);
                str8[strcspn(str8, "\n")] = 0;
                findBlankSpacesDigits(str8);
                break;
            case 9: // Exit
                printf("\nDo you want to Continue? (1 for Yes, 0 for No) : ");
                scanf("%d", &exid);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    }
}

