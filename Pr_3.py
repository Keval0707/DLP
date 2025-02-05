import re
KEYWORDS = {"int", "char", "return"}  
OPERATORS = {"=", "+", "-", "*", "/", "%"}
PUNCTUATION = {"(", ")", "{", "}", ",", ";"}
IDENTIFIER_REGEX = r"[a-zA-Z_][a-zA-Z_0-9]*"
CONSTANT_REGEX = r"\b\d+\b"
STRING_REGEX = r"'.'"
COMMENT_REGEX = r"//.*?$|/\*.*?\*/"
symbol_table = set()

def tokenize(code):
    code = re.sub(COMMENT_REGEX, "", code, flags=re.DOTALL)
    
    tokens = []
    errors = []
    modified_code = ""
    words = re.split(r'(\s+|"|\'|[{}(),;+*/%-])', code)
    
    for word in words:
        if not word or word.isspace():
            continue
        elif word in KEYWORDS:
            tokens.append(("Keyword", word))
        elif word in OPERATORS:
            tokens.append(("Operator", word))
        elif word in PUNCTUATION:
            tokens.append(("Punctuation", word))
        elif re.fullmatch(CONSTANT_REGEX, word):
            tokens.append(("Constant", word))
        elif re.fullmatch(STRING_REGEX, word):
            tokens.append(("String", word))
        elif re.fullmatch(IDENTIFIER_REGEX, word):
            tokens.append(("Identifier", word))
            symbol_table.add(word)
        else:
            errors.append(f"Lexical Error: {word}")
            
        modified_code += word + " "
    
    return tokens, errors, modified_code.strip()
code = """
int calculate(int a, int b) {
    // Local variables
    int sum = 0;
    int diff = 0;
    char operator = '+';
    
    /* Multiple line
       comment test */
    sum = a + b;
    diff = a - b;
    
    // Test invalid tokens
    int 123abc = 5;     // Invalid identifier
    char $name = 'X';   // Invalid identifier
    int value% = 100;   // Invalid identifier
    
    return sum;
}
"""
tokens, errors, modified_code = tokenize(code)

print("TOKENS")
for token in tokens:
    print(f"{token[0]}: {token[1]}")

print("\nSymbol Table:", symbol_table)
print("\nErrors:", errors)
print("\nModified Code:")
print(modified_code)
