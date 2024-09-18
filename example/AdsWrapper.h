#ifndef ADSWRAPPER_H
#define ADSWRAPPER_H

class AdsWrapper {
public:
    AdsWrapper();                 // Constructor
    ~AdsWrapper();                // Destructor

    void writeValue(std::ostream& out,int value);  // Method to set the value
         // Method to get the value

private:
    int m_value;               // Private member variable to store the value
};

#endif // MYCLASS_H