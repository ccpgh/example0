//
//  project: ptool
//  filename: tokenizer.h
//

#ifndef PTOOL_TOKENIZER_H
#define PTOOL_TOKENIZER_H

namespace ptool::parser::grammar
{

class Tokenizer
{
private:
  Tokenizer() = delete;
  bool operator==(const Tokenizer&) = delete;
  Tokenizer& operator=(const Tokenizer&)  = delete;
  Tokenizer(const Tokenizer&) = delete;
  ~Tokenizer() = delete;
  
  class Token
  {
  private:
    class Character
    {
    public:
      Character(const Character& character);
      bool operator==(const Character& character);
      Character& operator=(const Character& character);
  
      virtual ~Character()
      {}
    };
    
  public:
    Token(const Token& token);
    bool operator==(const Token& token);
    Token& operator=(const Token& token);
    
    virtual ~Token()
    {}
  };
  
public:
  class TokenizerFunctions
  {
  private:
    TokenizerFunctions() = delete;
    bool operator==(const TokenizerFunctions&) = delete;
    TokenizerFunctions& operator=(const Tokenizer&) = delete;
    TokenizerFunctions(const Tokenizer&) = delete;
    virtual ~TokenizerFunctions() = delete;

  public:
  };
  
};

} // namespace grammar::parser::ptool

#endif /* PTOOL_TOKENIZER_H */
