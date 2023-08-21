/***************************************************************************
 *   Copyright (C) 1965/1987/2023 by Serge Lussier                         *
 *   serge.lussier@oldlonecoder.club                                       *
 *                                                                         *
 *                                                                         *
 *   Unless otherwise specified, all code in this project is written       *
 *   by the author (Serge Lussier)                                         *
 *   and no one else then not even {copilot, chatgpt, or any other AI}     *
 *   --------------------------------------------------------------------- *
 *   Copyrights from authors other than Serge Lussier also apply here      *
 ***************************************************************************/

#pragma once
#include <dllibcc/dllib.h>
#include <xio/tokendata.h>


namespace dll
{

class  liblexer : public dllib
{

    void* lex{ nullptr };
public:
    liblexer() = delete;
    liblexer(book::object* parent_obj, const std::string& lib_id);
    ~liblexer() override;

    void assign_config(const char* src, xio::token_data::collection* tokens_tream);

    book::rem::code execute() override;


};

}
