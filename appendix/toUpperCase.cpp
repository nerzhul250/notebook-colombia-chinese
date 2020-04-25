int main()
{
    char str[] = "John is from USA.";

    cout << "The uppercase version of \"" << str << "\" is " << endl;

    for (int i=0; i<strlen(str); i++)
        putchar(toupper(str[i]));
    
    return 0;
}
