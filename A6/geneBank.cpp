#include "geneBank.h"


// =================================== PUBLIC FUNCTIONS =======================================================

GENE_BANK::GENE_BANK() 
{
    this->fileSize = 0;
    this->entryByte = sizeof(Sample);
}

GENE_BANK::~GENE_BANK() 
{
    cout << "Destructing ..." << endl;
}

bool cmp(Sample a, Sample b)
{
    return a.sampleID < b.sampleID;
}

void GENE_BANK::sort(Sample array[], int fileSize)
{

    int counter[5] = {0};
    for(int sample = 0; sample < fileSize; sample++)
    {
        counter[array[sample].speciesCode]++;
    }

    int position[5];
    position[0] = 0;
    for(int i = 1; i < 5; i++)
    {
        position[i] = position[i-1] + counter[i-1];
    }

    Sample* sorted = new Sample[fileSize];

    for(int sample = 0; sample < fileSize; sample++)
    {
        sorted[position[array[sample].speciesCode]] = array[sample];
        position[array[sample].speciesCode]++;
    }

    for(int sample = 0; sample < fileSize; sample++)
    {
        array[sample] = sorted[sample];
    }

}

void GENE_BANK::indexSamples(Sample array[], int indexArray[]) 
{
    this->p_index(array, indexArray);
}

void GENE_BANK::displayResearcher(int speciesCode, int offset, char* filename) 
{
    bool checkSample;

    checkSample = searchSample(speciesCode, offset, filename);

    if(checkSample){
        p_displayResearcher(speciesCode, offset, filename);
    } else {
        cout << "Sample record doesn't exist! Can't display researcher name." << endl;
    }
}

bool GENE_BANK::searchSample(int speciesCode, int offset, char* filename) 
{
    fstream sortedBinary;
    sortedBinary.open(filename, ios::in|ios::binary);

    if(fileSize < speciesCode + offset)
    {
        cout << "out of range" << endl;
        return false;
    }
    sortedBinary.seekg((speciesCode + offset) * entryByte, ios::beg);
    Sample temp;
    sortedBinary.read((char*) &temp, entryByte);

    if(temp.speciesCode == -1){
        cout << "Sample record doesn't exist" << endl;
        return false;
    }

    return true;


}


void GENE_BANK::updateResearcher(int speciesCode, int offset, char* newName, char* filename) 
{
    bool checkSample;

    checkSample = this->searchSample(speciesCode, offset, filename);

    if(checkSample){
        p_updateResearcher(speciesCode, offset, newName, filename);
    } else {
        cout << "Sample record to be updated doesn't exist!" << endl;
        p_updateResearcher(speciesCode, offset, newName, filename);
    }
}

void GENE_BANK::deleteSample(int speciesCode, int offset, char* filename)
{
    bool checkSample;

    checkSample = this->searchSample(speciesCode, offset, filename);

    if(checkSample){
        p_deleteSample(speciesCode, offset, filename);
    } else {
        cout << "Sample record to be deletesd doesn't exist!" << endl;
    }
}

void GENE_BANK::printSampleRange(int speciesCode, int startIndex, int endIndex, char* filename) 
{
    if(startIndex >= endIndex)
        throw MyException("ERROR: start index is larger than end index!");
    else
        this->p_printRange(speciesCode, startIndex, endIndex, filename);
}

// =================================== PRIVATE FUNCTIONS =======================================================

// your sorting algorithm here

void GENE_BANK::p_index(Sample array[], int indexArray[]) 
{
    for(int i = 0; i < 5; i++)
    {
        indexArray[i] = -1;
    }
    for(int sample = 0; sample < fileSize; sample++)
    {
        if(indexArray[array[sample].speciesCode] == -1)
        {
            indexArray[array[sample].speciesCode] = sample;
        }
    }

}

void GENE_BANK::p_displayResearcher(int speciesCode, int offset, char* filename) 
{
    /* These are the 5 unique species codes
        0 - H_SAP
        1 - M_MUS
        2 - D_MEL
        3 - E_COL
        4 - A_THA
    */
    fstream sortedBinary;
    sortedBinary.open(filename, ios::in|ios::binary);

    sortedBinary.seekg((speciesCode + offset) * entryByte, ios::beg);
    Sample temp;
    sortedBinary.read((char*) &temp, entryByte);
    cout << "Researcher name: " << temp.researcher << endl;

}

void GENE_BANK::p_updateResearcher(int speciesCode, int offset, char* newName, char* filename) 
{
    fstream sortedBinary;
    sortedBinary.open(filename, ios::in | ios::out |ios::binary);

    sortedBinary.seekg((speciesCode + offset) * entryByte, ios::beg);
    Sample temp;
    sortedBinary.read((char*) &temp, entryByte);
    //cout << "Prev researcher name: " << temp.researcher << endl;



    strcpy(temp.researcher, newName);

    sortedBinary.seekp((speciesCode + offset) * entryByte, ios::beg);
    sortedBinary.write((char*) &temp, entryByte);
    //cout << "Updated researcher name: " << temp.researcher << endl;
    sortedBinary.close();


}

void GENE_BANK::p_deleteSample(int speciesCode, int offset, char* filename) 
{
    fstream sortedBinary;
    sortedBinary.open(filename, ios::in | ios::out |ios::binary);

    sortedBinary.seekg((speciesCode + offset) * entryByte, ios::beg);
    Sample temp;
    sortedBinary.read((char*) &temp, entryByte);
    //cout << "Prev researcher name: " << temp.researcher << endl;


    temp.speciesCode = -1;

    sortedBinary.seekp((speciesCode + offset) * entryByte, ios::beg);
    sortedBinary.write((char*) &temp, entryByte);
    sortedBinary.close();

}

void GENE_BANK::p_printRange(int speciesCode, int startIndex, int endIndex, char* filename) 
{
    fstream sortedBinary;
    sortedBinary.open(filename, ios::in | ios::out |ios::binary);

    for(int i = startIndex; i <= endIndex; i++)
    {
        sortedBinary.seekg((speciesCode + i) * entryByte, ios::beg);
        Sample temp;
        sortedBinary.read((char*) &temp, entryByte);
        if(temp.speciesCode != -1)
            cout << "Sample ID: " << temp.sampleID << ", Species Code: " << temp.speciesCode << ", Purity Score: " << temp.purityScore << ", Researcher: " << temp.researcher << endl;
    }
}
