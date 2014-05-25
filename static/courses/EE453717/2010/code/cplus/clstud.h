class CStudent
{
    std::string Name;
    double CPI;
    double *SPI;
    int NumSem;
public:
    CStudent(std::string Name, double* SPI, int NumSem)
    {
        this->Name = Name;
        this->NumSem = NumSem;
        this->SPI = new double[NumSem];
        for(int i = 0; i < NumSem; i++)
        {
            this->SPI[i] = SPI[i];
        }
        calculateCPI();
    }

    CStudent(const CStudent& stud) 
        : Name(stud.Name),
          NumSem(stud.NumSem),
          CPI(stud.CPI)
    {
        this->SPI = new double[NumSem];
        for (int i = 0; i < NumSem; i++)
        {
            this->SPI[i] = stud.SPI[i];
        }
    }

    ~CStudent()
    {
        delete[] SPI;
    }

    std::string getName() const
    {
        return Name;
    }

    double getCPI() 
    {
        return calculateCPI();
    }

    void setSPI(int SemIndex, double SPI)
    {
        this->SPI[SemIndex] = SPI;
    }

    bool operator>(CStudent rhs)
    {
        if(this->CPI > rhs.getCPI())
            return true;
        else
            return false;
    }


private:
    double calculateCPI()
    {
        CPI = 0.0;
        for(int i = 0; i < NumSem; i++)
        {
            CPI += this->SPI[i];
        }
        CPI = CPI/NumSem;

        return CPI;
    }

};
