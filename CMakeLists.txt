cmake_minimum_required(VERSION 3.16.3)
project(project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project1
        Automaton.h
        ColonAutomaton.h
        ColonDashAutomaton.h
        Lexer.cpp
        main.cpp
        Lexer.h
        Token.cpp
        Token.h
        Undefined.h QueriesAutomaton.h StringAutomaton.h CommentAutomaton.h FactsAutomaton.h RulesAutomaton.h SchemesAutomaton.h IDAutomaton.h Matcher.h LeftParenAutomaton.h RightParenAutomaton.h PeriodAutomaton.h CommaAutomaton.h QMarkAutomaton.h EOFAutomaton.h BlockCommentAutomaton.h CommentAutomaton.h AddAutomaton.h MultiplyAutomaton.h)
