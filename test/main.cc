#include <lexer/lexer_color.h>



auto main(int argc, char** argv) -> int
{
    xio::token_data::collection tokens;

    std::string code = "arc = 5 * 4ac(3 + 2b);";
    lexer lex;
    lex.config() =
    {
        code.c_str(),
        &tokens
    };

    auto R = lex();
    if(!R == book::rem::accepted)
    {
        std::cout << "lexer failed. See error descriptions in the book logs.\n";
        return -1;
    }
    for(auto t : tokens)
    {
        std::cout << t.details() << '\n';
    }

    lexer_color lc;
    R = lc.process(code,tokens);
    // for now ignore R
    std::cout << lc.Product() << '\n';
    book::rem::clear(nullptr);

    return 0;
}