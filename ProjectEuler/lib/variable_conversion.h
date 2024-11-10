#include <stdint.h>
#include <stdio.h>

typedef struct
{
    char buffer[22]; // Max 20 digits + 1 for sign + 1 for null terminator
    uint8_t length;
} string_t;

void lib_reverse_string(string_t *str_var);

bool lib_check_palindrome(string_t *str_var);

string_t lib_int_to_str(int64_t num);



void lib_reverse_string(string_t *str_var)
{
    uint8_t length = str_var->length;
    uint8_t start = 0;
    uint8_t end = length - 1;

    while (start < end)
    {
        // XOR swap: Swap str[start] and str[end] without a temp variable
        str_var->buffer[start] ^= str_var->buffer[end];
        str_var->buffer[end] ^= str_var->buffer[start];
        str_var->buffer[start] ^= str_var->buffer[end];
        start++;
        end--;
    }
}

bool lib_check_palindrome(string_t *str_var)
{
    uint8_t length = str_var->length;
    uint8_t start;
    uint8_t end= length - 1;
    /* Ignore sign if there is*/
    if (str_var->buffer[0] == '-')
    {
        start = 1;
    }
    else
    {
        start = 0;
    }

    /* Check palindrome*/
    while (start < end)
    {
        if (str_var->buffer[start] == str_var->buffer[end])
            ;
        else
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string_t lib_int_to_str(int64_t num)
{
    string_t result;
    result.length = 0;

    // Handle negative numbers
    uint8_t is_negative = 0;
    if (num < 0)
    {
        is_negative = 1;
        num = -num; // Convert to positive for easier processing
    }

    // Process each digit in reverse order
    do
    {
        result.buffer[result.length++] = (num % 10) + '0'; // Convert digit to character
        num /= 10;
    } while (num != 0);

    // Add the negative sign if needed
    if (is_negative)
    {
        result.buffer[result.length++] = '-';
    }

    result.buffer[result.length] = '\0'; // Null-terminate the string

    // Reverse the string in place to get the correct order
    lib_reverse_string(&result);

    return result;
}
