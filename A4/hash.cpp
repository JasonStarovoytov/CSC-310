#include "hash.h"

// Constructor - initializing table based on chosen hash table variant
HashTable::HashTable(int size, CollisionHandling variant) 
{
    tableSize = size; 
    elementCount = 0; 
    method = variant;
    switch (method) {
        case CHAINING_VECTOR:
            tableVector.resize(size);
            break;
        case CHAINING_LIST:
            tableList.resize(size);
            break;
        case CHAINING_BST:
            tableBST.resize(size);
            break;
        case LINEAR_PROBING:
        case QUADRATIC_PROBING:
        case DOUBLE_HASHING:
            tableProbing.resize(size);
            break;
    }
}

HashTable::~HashTable() {}

int HashTable::hash1(const string& key) const {
    unsigned long hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c);
    }
    return hash % tableSize;
}

int HashTable::hash2(const string& key) const {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return 1 + (hash % (tableSize - 1));
}

// complete this
int HashTable::probe(int index, int i, string key) const {
    switch (method) {
        case LINEAR_PROBING:
            return (index + i) % tableSize;
        case QUADRATIC_PROBING:
            return (index + i * i) % tableSize;
        case DOUBLE_HASHING:
            return (index + i * hash2(key)) % tableSize;
        default:
            return index;
    }
}
void HashTable::insert(const string& key, int value) {
    resizeIfNeeded();
    int index = hash1(key);

    switch (method) {
        case CHAINING_VECTOR:
            for (auto& pair : tableVector[index]) {
                if (pair.first == key) {
                    pair.second = value; // Key already exists, update the value
                    return;
                }
            }
            tableVector[index].push_back({key, value});
            break;

        case CHAINING_LIST:
            for (auto& pair : tableList[index]) {
                if (pair.first == key) {
                    pair.second = value; // Key already exists, update the value
                    return;
                }
            }
            tableList[index].push_front({key, value});
            break;

        case CHAINING_BST:
            tableBST[index].insert(key, value);
            break;

        case LINEAR_PROBING:
        case QUADRATIC_PROBING:
        case DOUBLE_HASHING:
            index = findEmptySlot(key);
            tableProbing[index].first = key;
            tableProbing[index].second = value;

            break;
    }
    elementCount++;
}

bool HashTable::search(const string& key, int& value) {
    int hash = hash1(key);
    int i = 0;

    switch (method)
    {
    case CHAINING_VECTOR:
        for (auto& pair : tableVector[hash]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        
        break;

    case CHAINING_LIST:
        for (auto& pair : tableList[hash]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        
        break;

    case CHAINING_BST:
        return tableBST[hash].search(key, value);

        break;

    case LINEAR_PROBING:
    case QUADRATIC_PROBING:
    case DOUBLE_HASHING:
        while (i < tableSize) {
            int probeIndex = probe(hash, i, key);
            if (tableProbing[probeIndex].first == key) {
                value = tableProbing[probeIndex].second;
                return true;
            }
            i++;
        }

        break;
    
    default:
        break;
    }
    return false;
}

bool HashTable::remove(const string& key) {
    int hash = hash1(key);
    int i = 0;
    bool deleted = false;
    switch (method)
    {
    case CHAINING_VECTOR:
        for (auto it = tableVector[hash].begin(); it != tableVector[hash].end(); ++it) {
            if(!it->first.empty()){
                if (it->first == key) {
                    tableVector[hash].erase(it);
                    elementCount--;
                    deleted = true;
                    break;
                }
            }
        }
        
        break;

    case CHAINING_LIST:
        for (auto it = tableList[hash].begin(); it != tableList[hash].end(); ++it) {
            if(!it->first.empty()){
                if (it->first == key) {
                    tableList[hash].erase(it);
                    elementCount--;
                    deleted = true;
                    break;
                }
            }
        }
        
        break;

    case CHAINING_BST:
        if(tableBST[hash].remove(key)){
            elementCount--;
            deleted = true;
        }
        
        break;

    case LINEAR_PROBING:
    case QUADRATIC_PROBING:
    case DOUBLE_HASHING:
        while (i < tableSize) {
            int probeIndex = probe(hash, i, key);
            if (tableProbing[probeIndex].first == key) {
                tableProbing[probeIndex].first = "DELETED";
                deleted = true;
                elementCount--;
                break;
            }
            i++;
        }

        break;
    
    default:
        break;
    }

    return deleted;
}

// Function to read data from file
vector<pair<string, int>> readDataFromFile(const string& filename) {
    vector<pair<string, int>> data;
    ifstream file(filename);
    string key;
    int value;
    if (!file) {
        cerr << "Error reading file: " << filename << endl;
        return data;
    }
    while (file >> key >> value) {
        data.push_back({key, value});
    }

    file.close();
    return data;
}

// Benchmark function for custom HashTable
void HashTable::benchmarkHashTable(HashTable& table, const vector<pair<string, int>>& data, int numSearch, int numDelete) {
    auto start = chrono::high_resolution_clock::now();

    // Insertions
    for (const auto& pair : data) {
        table.insert(pair.first, pair.second);
    }

    auto insertEnd = chrono::high_resolution_clock::now();

    // Searches
    int value;
    for (int i = 0; i < numSearch; ++i) {
        table.search(data[rand() % data.size()].first, value);
    }

    auto searchEnd = chrono::high_resolution_clock::now();

    // Deletions
    for (int i = 0; i < numDelete; ++i) {
        table.remove(data[rand() % data.size()].first);
    }

    auto end = chrono::high_resolution_clock::now();

    auto insertTime = chrono::duration_cast<chrono::microseconds>(insertEnd - start);
    auto searchTime = chrono::duration_cast<chrono::microseconds>(searchEnd - insertEnd);
    auto deleteTime = chrono::duration_cast<chrono::microseconds>(end - searchEnd);

    cout << "Insertion time: " << insertTime.count() << " microseconds" << endl;
    cout << "Search time: " << searchTime.count() << " microseconds" << endl;
    cout << "Deletion time: " << deleteTime.count() << " microseconds" << endl;
}

void HashTable::displayStats() {
    int totalElements = 0;
    int maxChainLength = 0;
    int emptyBuckets = 0;

    switch (method) {
        case CHAINING_VECTOR:
            for (const auto& bucket : tableVector) {
                if (bucket.empty()) emptyBuckets++;
                maxChainLength = max(maxChainLength, (int)bucket.size());
                totalElements += bucket.size();
            }
            break;
        case CHAINING_LIST:
            for (const auto& bucket : tableList) {
                if (bucket.empty()) emptyBuckets++;
                maxChainLength = max(maxChainLength, (int)bucket.size());
                totalElements += bucket.size();
            }
            break;
        case CHAINING_BST:
            for (const auto& bucket : tableBST) {
                vector<pair<string, int>> elements = bucket.inOrderTraversal();
                if (elements.empty()) {
                    emptyBuckets++;
                } else {
                    maxChainLength = max(maxChainLength, (int)elements.size());
                    totalElements += elements.size();
                }
            }
            break;
        case LINEAR_PROBING:
        case QUADRATIC_PROBING:
        case DOUBLE_HASHING:
            for (const auto& entry : tableProbing) {
                if (!entry.first.empty()) totalElements++;
                else emptyBuckets++;
            }
            break;
    }

    cout << "Total elements: " << totalElements << endl;
    cout << "Load factor: " << (double)totalElements / tableSize << endl;
    cout << "Empty buckets: " << emptyBuckets << endl;
    if (method == CHAINING_VECTOR || method == CHAINING_LIST || method == CHAINING_BST) {
        cout << "Max chain length: " << maxChainLength << endl;
    }
}


void HashTable::rehash() {
    vector<pair<string, int>> newTable;
    cout << "REHASH" << (double)elementCount<< endl;
    switch (method){
        case CHAINING_VECTOR:
            for (const auto& bucket : tableVector) {
                for(const auto& pair : bucket){
                    newTable.push_back(pair);
                } 
            }
            tableVector.clear();
            tableVector.resize(tableSize);
            
            break;

        case CHAINING_LIST:
            for (const auto& bucket : tableList) {
                for(const auto& pair : bucket){
                    newTable.push_back(pair);
                } 
            }
            tableList.clear();
            tableList.resize(tableSize);
            
            break;

        case CHAINING_BST:

            for (const auto& bucket : tableBST) {

                vector<pair<string, int>> elements = bucket.inOrderTraversal();

                newTable.insert(newTable.end(), elements.begin(), elements.end());
            }
            tableBST.clear();
            tableBST.resize(tableSize);
            
            break;
        
        case LINEAR_PROBING:
        case QUADRATIC_PROBING:
        case DOUBLE_HASHING:
            for (const auto& entry : tableProbing) {
                if (!entry.first.empty() && entry.first != "DELETED"){
                    newTable.push_back(entry);
                }
            }
            tableProbing.clear();
            tableProbing.resize(tableSize);
            break;
        
        default:
        break;
    }

    elementCount = 0; // reset element count before reinserting
    for(const auto& pair : newTable){
        insert(pair.first, pair.second);
    }
}


int HashTable::findEmptySlot(const string& key) { // finds empty or deleted slot unless key exists already
    int index = hash1(key);
    int i = 0;
    while (i < tableSize) {
        int probeIndex = probe(index, i, key);
        if (tableProbing[probeIndex].first.empty() || tableProbing[probeIndex].first == key || tableProbing[probeIndex].first == "DELETED") {
            return probeIndex;
        }
        i++;
    }
}

// try experimenting with different thresholds for each technique
void HashTable::resizeIfNeeded() {
    if((double) elementCount / (double) tableSize >= 0.7){
        tableSize *= 2;
        rehash();
    }
}

// Benchmark function for built-in hash table in C++
void benchmarkStdUnorderedMap(const vector<pair<string, int>>& data, int numSearch, int numDelete) {
    unordered_map<string, int> stdMap;

    auto start = chrono::high_resolution_clock::now();

    // Insertions
    for (const auto& pair : data) {
        stdMap[pair.first] = pair.second;
    }

    auto insertEnd = chrono::high_resolution_clock::now();

    // Searches
    int value;
    for (int i = 0; i < numSearch; ++i) {
        auto it = stdMap.find(data[rand() % data.size()].first);
        if (it != stdMap.end()) {
            value = it->second;
        }
    }

    auto searchEnd = chrono::high_resolution_clock::now();

    // Deletions
    for (int i = 0; i < numDelete; ++i) {
        stdMap.erase(data[rand() % data.size()].first);
    }

    auto end = chrono::high_resolution_clock::now();

    auto insertTime = chrono::duration_cast<chrono::microseconds>(insertEnd - start);
    auto searchTime = chrono::duration_cast<chrono::microseconds>(searchEnd - insertEnd);
    auto deleteTime = chrono::duration_cast<chrono::microseconds>(end - searchEnd);

    cout << "std::unordered_map Benchmark Results:" << endl;
    cout << "Insertion time: " << insertTime.count() << " microseconds" << endl;
    cout << "Search time: " << searchTime.count() << " microseconds" << endl;
    cout << "Deletion time: " << deleteTime.count() << " microseconds" << endl;
}