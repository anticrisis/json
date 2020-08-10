//
// Copyright (c) 2020 Krystian Stasiowski (sdkrystian@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/cppalliance/json
//

#ifndef BOOST_JSON_PARSE_OPTIONS_HPP
#define BOOST_JSON_PARSE_OPTIONS_HPP

namespace boost {
namespace json {

/** Parser Extensions.
    
    The parser can be configured to enable
    certain extensions. By default, only conformant
    JSON is accepted.
    
    The currently supported extensions are:
    
    <li> Comments, which permit comments
    to appear within whitespace, and

    <li> Trailing commas, which allow a comma
    to appear after the last element of an object or array.

    <li> Skip UTF-8 validation, which skip checking
    the validity of UTF-8 byte sequences.
*/
struct parse_options
{
#if __cplusplus < 201402L
    parse_options(
        bool allow_comments_ = false, 
        bool allow_trailing_commas_ = false,
        bool allow_invalid_utf8_ = false) noexcept
        : allow_comments(allow_comments_)
        , allow_trailing_commas(allow_trailing_commas_)
        , allow_invalid_utf8(allow_invalid_utf8_)
    {
    }

    bool allow_comments;
    bool allow_trailing_commas;
    bool allow_invalid_utf8;
#else
    bool allow_comments = false;
    bool allow_trailing_commas = false;
    bool allow_invalid_utf8 = false;
#endif
};

} // json
} // boost

#endif