/*==================================================
LIB:
    String Utility Library

    This library provides utility functions for working with integer-to-string
    conversions and string manipulations, specifically for:
    - Reversing a string in-place
    - Checking if a string is a palindrome (ignoring negative signs)
    - Converting an integer to a string representation

    Functions included:
    - lib_reverse_string: Reverses a string in-place
    - lib_check_palindrome: Checks if a string is a palindrome
    - lib_int_to_str: Converts an integer to a string
====================================================*/

#include <stdint.h>
#include <stdio.h>

typedef struct
{
    char buffer[22]; // Max 20 digits + 1 for sign + 1 for null terminator
    uint8_t length;  // Holds the length of the string in the buffer
} string_t;

/**
 * Reverses the characters in a given string (excluding the null terminator).
 *
 * @param str_var Pointer to a string_t structure containing the string to reverse.
 */
void lib_reverse_string(string_t *str_var)
{
    uint8_t length = str_var->length;
    uint8_t start = 0;
    uint8_t end = length - 1;

    while (start < end)
    {
        // XOR swap: Swap characters at start and end indices without using a temporary variable
        str_var->buffer[start] ^= str_var->buffer[end];
        str_var->buffer[end] ^= str_var->buffer[start];
        str_var->buffer[start] ^= str_var->buffer[end];
        start++;
        end--;
    }
}

/**
 * Checks if a given string is a palindrome (ignoring the sign for numbers).
 *
 * @param str_var Pointer to a string_t structure containing the string to check.
 * @return true if the string is a palindrome, false otherwise.
 */
bool lib_check_palindrome(string_t *str_var)
{
    uint8_t length = str_var->length;
    uint8_t start;
    uint8_t end = length - 1;

    // Ignore the sign character if it exists
    if (str_var->buffer[0] == '-')
    {
        start = 1; // Start comparison after the negative sign
    }
    else
    {
        start = 0;
    }

    // Check if the string is a palindrome
    while (start < end)
    {
        if (str_var->buffer[start] != str_var->buffer[end])
        {
            return false; // Return false if any mismatch is found
        }
        start++;
        end--;
    }
    return true; // Return true if the entire string matches symmetrically
}

/**
 * Converts an integer to a string representation and stores it in a string_t structure.
 *
 * @param num The integer to convert to a string.
 * @return A string_t structure containing the string representation of the integer.
 */
string_t lib_int_to_str(int64_t num)
{
    string_t result;
    result.length = 0;

    // Handle negative numbers by marking and converting to positive
    uint8_t is_negative = 0;
    if (num < 0)
    {
        is_negative = 1;
        num = -num; // Convert to positive for easier digit extraction
    }

    // Process each digit in reverse order and store it in the buffer
    do
    {
        result.buffer[result.length++] = (num % 10) + '0'; // Convert digit to character
        num /= 10;
    } while (num != 0);

    // Add the negative sign if the number was originally negative
    if (is_negative)
    {
        result.buffer[result.length++] = '-';
    }

    result.buffer[result.length] = '\0'; // Null-terminate the string

    // Reverse the string in place to get the correct order
    lib_reverse_string(&result);

    return result;
}
