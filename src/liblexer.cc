#include "lexer/liblexer.h"

#include "lexer/lexer_color.h"

namespace dll
{


liblexer::liblexer(book::object* parent_obj, const std::string& lib_id) : dllib(parent_obj, lib_id) {}

void liblexer::assign_config(const char* src, xio::token_data::collection* tokens_tream)
{
    lex = new lexer;
    static_cast<lexer*>(lex)->config() =
    {
        src, 
        tokens_tream
    };
}



liblexer::~liblexer()
{
    delete lex;
}

book::rem::code liblexer::execute()
{
    return static_cast<lexer*>(lex)->Exec();
}



}




BEGIN_EXPORT


book::rem::code init_lexer(dll::dllib* lib, const char* code, xio::token_data::collection* tokens)
{
    dll::liblexer* lex = dynamic_cast<dll::liblexer*>(lib);
    lex->assign_config(code, tokens);
    return rem::accepted;
}

EXPORT_SYMBOLS
{
    dll::dllib::interface_map im =
    {
        {"init_lexer", init_lexer},
    };

    return im;
}

CREATE_INSTANCE
{
    return new dll::liblexer(parent_obj, obj_id);
}


DELETE_INSTANCE
{
    delete dllib;
}

END_EXPORT






