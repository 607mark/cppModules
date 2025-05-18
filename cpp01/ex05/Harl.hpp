#pragma once
#include <string>
class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        void complain( std::string level );

        typedef void (Harl::*HarlFunc) (void);

        struct Level {
            std::string levelStr;
            HarlFunc function;
        } ;

        Level LevelList[4] = {
            {"DEBUG", &Harl::debug},
            {"INFO", &Harl::info},
            {"WARNING", &Harl::warning},
            {"ERROR", &Harl::error}
        } ;

        
} ;