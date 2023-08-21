
#include <dllibcc/dllib.h>
#include <xio/tokendata.h>

auto main(int argc, char** argv) -> int
{

    dll::dll_file file(nullptr, "lexer");
    
    if (file.open() != book::rem::ok)
    {
        book::rem::push_message(HERE) << " lexer plugin failed ... ;(";
        book::rem::clear(nullptr);
        return -1;
    }

    xio::token_data::collection tokens;
    std::string code = "result= 5 * 4ac(3 + 2b);";
    //...
    book::rem::code c = file.lib()->call<book::rem::code>("assign_config");
    if (c != book::rem::accepted) return -1;
    file.lib()->execute();

    book::rem::push_message(HERE) << " closing the lexer library:";
    auto R =  file.close();
    book::rem::clear(nullptr);
    return R;
}

//#include <lexer/lexer_color.h>
//
//
//
//auto main(int argc, char** argv) -> int
//{
//    xio::token_data::collection tokens;
//
//    std::string code = "result= 5 * 4ac(3 + 2b);";
//    lexer lex;
//    lex.config() =
//    {
//        code.c_str(),
//        &tokens
//    };
//
//    auto R = lex();
//    if(R != book::rem::accepted)
//    {
//        std::cout << "lexer failed. See error descriptions in the book logs.\n";
//        return -1;
//    }
//
//
//    for(auto const& t : tokens)
//    {
//        std::cout << t.details(true) << '\n';
//    }
//
//    lexer_color lc;
//    lc << lex.config();
//    // for now ignore lc rem::code return value
//    rem::push_message(HERE) << "Lexer & lexer_color tests results:";
//    rem::out() << lc.Product() << '\n';
//    rem::out() << lc.mark(tokens[5]) << '\n';
//
//    book::rem::clear(nullptr);
//
//    return 0;
//}
