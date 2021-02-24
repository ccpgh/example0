//
//  project: ptool
//  filename: parser.h
//

#ifndef PTOOL_PARSER_H
#define PTOOL_PARSER_H

#include <deque>
#include <string>

namespace ptool::parser::grammar
{

class Parser
{
private:
  Parser() = delete;
  Parser operator==(const Parser&) = delete;
  Parser operator=(const Parser&) = delete;
  Parser(const Parser&)  = delete;
  virtual ~Parser() = delete;

public:
  
  bool parse(const std::deque<char>& buffer);
};

} // namespace grammar::parser::ptool

#endif /* PTOOL_PARSER_H */
