#include <iostream>
#include <string>
#include <unordered_map>

typedef std::string String ;
typedef std::unordered_map<String, String> URIMap ;

URIMap generateURIMap(String uriString) ;
void displayValuesForKeys(const URIMap& map) ;
bool isContainedInAlpha(char ch) ;

int main(int argc, char* argv[]) {
    String content = "" ;

    std::cout << "Content-type: text/html\r\n\r\n charset=UTF8" ;

    std::cout << "<html>\n" ;

    std::cout << "<head>\n" ;
    std::cout << "<title>Text Field Input CGI</title>\n" ;
    std::cout << "<style>\n" ;
    std::cout << ".title-style { font-family: \'Helvetica\'; font-size: 35px ; }\n" ;
    std::cout << ".input-style { width: 200px ; height: 55 ; border: 2px solid #000 ; border-radius: 5px ; text-align: center ; }\n" ;
    std::cout << ".button-style { width: 200px ; height: 55 ; border: 2px solid #01fdd3 ; transition: 0.5s ; " ;
    std::cout << "background-color: #fff ; color: #01fdd3 ; border-radius: 5px ; cursor: pointer ; }\n" ;
    std::cout << ".button-style:hover { background-color: #01fdd3 ; color: #ffffff ; font-weight: 700 ; }" ;
    std::cout << "</style>\n" ;
    std::cout << "<script>\n" ;
    std::cout << "let textField = document.getElementById('text-field')\n" ;
    std::cout << "textField.addEventListener('focus', (event) => { event.target.placeholder = \"Write\" } )" ;
    std::cout << "</script>\n" ;
    std::cout << "</head>\n" ;

    std::cout << "<body>\n" ;
    std::cout << "<h1 class=\"title-style\">CGI (Common Gateway Interface)</h1>\n" ;
    std::cout << "<form action=\"form.bin\" method=\"post\">\n" ;
    std::cout << "<input type=\"text\" name=\"name\" placeholder=\"Enter your name\" class=\"input-style\" id=\"text-field\">\n" ;
    std::cout << "<input type=\"text\" name=\"lastname\" placeholder=\"Enter your lastname\" class=\"input-style\" id=\"text-field\">\n" ;
    std::cout << "<input type=\"submit\" name=\"submit\" value=\"Send\" class=\"button-style\">\n" ;
    std::cout << "</form>\n" ;

    std::cin >> content ;
    
    if (content != "") {
        URIMap uriMap = generateURIMap(content) ;
        std::cout << "<h2>Hello! your name is: " << uriMap["name"] << "</h2>\n";
        std::cout << "<h2>Your lastname is: " << uriMap["lastname"] << "</h2>\n" ;
    }    

    // std::cout << "<h1>Hello " << content << "!</h1>\n" ;

    std::cout << "</body>\n" ;

    std::cout << "</html>\n" ;

    return 0 ;
}

URIMap generateURIMap(String uriString) {
    URIMap result ;
    String equal = "=" ;
    String ampersand = "&" ;
    String percentage = "%" ;
    std::size_t position = 0 ;
    String key ;
    String value ;
    // String innerCodeValue ;

    while ((position = uriString.find(equal)) != String::npos) {
        key = uriString.substr(0, position) ;
        uriString.erase(0, position + equal.length()) ;
        value = uriString.substr(0, uriString.find(ampersand)) ;
        std::size_t index = 0 ; 
        uriString.erase(0, uriString.find(ampersand) + ampersand.length()) ;
        result[key] = value ;
    } 

    return result ;
}

