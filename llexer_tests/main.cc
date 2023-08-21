

#include <lexer/lexer_color.h>


#include <lexer/lexer_color.h>



auto main(int argc, char** argv) -> int
{
    xio::token_data::collection tokens;

    std::string code = "result= 5 * 4ac(3 + 2b);";
    lexer lex;
    lex.config() =
    {
        code.c_str(),
        &tokens
    };

    auto R = lex();
    if(R != book::rem::accepted)
    {
        std::cout << "lexer failed. See error descriptions in the book logs.\n";
        return -1;
    }


    for(auto const& t : tokens)
    {
        std::cout << t.details(true) << '\n';
    }

    lexer_color lc;
    lc << lex.config();
    // for now ignore lc rem::code return value
    rem::push_message(HERE) << "Lexer & lexer_color tests results:";
    rem::out() << lc.Product() << '\n';
    rem::out() << lc.mark(tokens[5]) << '\n';

    book::rem::clear(nullptr);

    return 0;
}
