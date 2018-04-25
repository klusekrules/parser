#pragma once
#pragma warning( disable : 4251 )
#pragma warning( disable : 4275 )
#ifdef _WIN32
#   define PARSER_API __declspec(dllexport)
#	define PARSER_EXPIMP_TEMPLATE
#else
#   define PARSER_API
#endif