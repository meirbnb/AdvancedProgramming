#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct TransactionData{
    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;
    TransactionData(double amount, string senderKey, string receiverKey, time_t timestamp){
        this->amount = amount;
        this->senderKey = senderKey;
        this->receiverKey = receiverKey;
        this->timestamp = timestamp;
    };
    TransactionData(){};
    string toString(){
        stringstream result;
        result << "Amount: " << amount << "\nSenderKey: " << senderKey << "\nReceiverKey: " << receiverKey << "\nTime: " << timestamp << "\n";
        return result.str();
    }
};

class Block{
private:
    int index;
    TransactionData transaction_data;
    size_t block_hash;
    size_t prev_hash;
public:
    Block(int index, TransactionData transaction_data, size_t prev_hash){
        this->index = index;
        this->transaction_data = transaction_data;
        this->prev_hash = prev_hash;
        this->block_hash = generateHash();
    }
    int getIndex(){
        return index;
    }
    TransactionData getTransactionData(){
        return transaction_data;
    }
    size_t getBlockHash(){
        return block_hash;
    }
    size_t getPrevHash(){
        return prev_hash;
    }
    size_t generateHash(){
        string toHashS = to_string(transaction_data.amount) + transaction_data.receiverKey + transaction_data.senderKey + to_string(transaction_data.timestamp);
        hash<string> tDataHash;
        hash<string> prevHash;
        return tDataHash(toHashS) ^ (prevHash(to_string(prev_hash)) << 1);
    }
    string toString(){
        stringstream result;
        result << "Index: " << index << "\nTransactionData: " << transaction_data.toString() << "\nBlockHash: " << block_hash << "\nPrevHash: " << prev_hash << "\n";
        return result.str();
    }
};

class Blockchain{
private:
    vector<Block>chain;
    //Has one constructor: 
    Blockchain(){
        Block firstBlock = createFirstBlock(); 
        chain.push_back(firstBlock);
    }
    Block createFirstBlock(){
        time_t current;
        // Setup Initial Transaction Data
        TransactionData dataFirstBlock(0, "FirstBlock", "FirstBlock", time(&current));
        Block firstBlock (0, dataFirstBlock, 0);
        return firstBlock;
    }
    void addBlock(TransactionData data){
        int index = (int)chain.size();
        size_t previousHash = getLatestBlock()->getBlockHash();
        Block newBlock(index, data, previousHash);
        chain.push_back(newBlock);
    }
    Block *getLatestBlock(){
        return &chain.back();
    }
    void printBlockchain(){
        vector<Block>::iterator it = chain.begin();
        while(it != chain.end()){
            cout << it->toString() << '\n';
            ++it;
        }
    }
    bool isBlockchainValid(){
        vector<Block>::iterator it = chain.begin();
        while(it != chain.end()){
            if (it->generateHash() != it->getBlockHash())
                return false;
            ++it;
        }
        return true;
    }
};

class Miner{
    void mine(Blockchain blockchain, TransactionData data){
        // write here later
    }
};

int main(){
    // also here
    return 0;
}
