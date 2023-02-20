//definir una clase

#include <iostream>
#include <string>

class SimpleContact
{
  public:
    SimpleContact (const std::string& name, const std::string& phone);

    std::string
    getName () const;
    std::string
    getPhone () const;

    void
    setName (const std::string& name);
    void
    setPhone (const std::string& phone);

  private:
    std::string m_name;
    std::string m_phone;
};