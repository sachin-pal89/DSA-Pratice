#include <iostream>
#include <string>
using namespace std;

// Creating a  Node Class So that to form a linked list
template <typename T>
class MapNode
{
public:
    string key;
    T value;
    MapNode<T> *next;

    MapNode(string key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

// Now to Create a Hashmap
template <typename T>
class HashMap
{
public:
    MapNode<T> **bucket;
    int count;
    int NumSize;

    HashMap()
    {
        count = 0;
        NumSize = 5;
        bucket = new MapNode<T>*[NumSize];
        for (int i = 0; i < NumSize; i++)
        {
            bucket[i] = NULL;
        }
    }

    int getSize()
    {
        return count;
    }

private:
    // Use to get the appropiate index to put the data
    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int currentstate = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currentstate;
            hashcode = hashcode % NumSize;

            currentstate *= 37;  // Considered 37 as base value
            currentstate = currentstate % NumSize;
        }

        return hashcode % NumSize;
    }

    // To ReHash The HashMap 
    void rehash()
    {
        // Load factor = (no.of enteries) / no.of boxes in BucketArray


        MapNode<T>** temp = bucket;

        // Create a new hashmap with more size
        bucket = new MapNode<T>*[2 * NumSize];

        // Empty the New hashMap
        for(int i = 0; i < 2 * NumSize; i++)
        {
            bucket[i] = NULL;
        }

        int oldNumSize = NumSize;
        count = 0;
        NumSize *= 2;

        // Insert All Entries in old hashMap to new hashmap
        for(int i = 0; i < oldNumSize; i++)
        {
            MapNode<T>* head = temp[i];
           
            // Inserting all nodes in this Index to their respective position in new HashMap according to the new Size of HashMap
            while(head != NULL)
            {
                string key = head->key;
                T value = head->value;
                insert(key,value);
                head = head->next;
            }
        }

        // Deleting all Entries in older Hashmap
        for(int i = 0; i < oldNumSize; i++)
        {
            MapNode<T>* head = temp[i];
            delete head;
        }
        delete [] temp;

    }

public:

    // Insertion of key and Value in HashMap
    void insert(string key, T value)
    {
        int BucketIndex = getBucketIndex(key);
        MapNode<T> *head = bucket[BucketIndex];

        while (head != NULL)
        {
            // If key Already Exist the just updating it
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = bucket[BucketIndex];
        MapNode<T>*node = new MapNode<T>(key, value);
        node->next = head;
        bucket[BucketIndex] = node;
        count++;

        // To maintain The Load factor of the HashMap
        double LoadFactor = (1.0 * count) / NumSize;
        if(LoadFactor > 0.7)
        {
            // So if Load Factor > 0.7 then we need to rehash so as to maintain the complexity
            rehash();
        }
    }

    // Deletion of key and Value in HashMap
    T deletion(string key)
    {
        int BucketIndex = getBucketIndex(key);
        MapNode<T>* head = bucket[BucketIndex];
        MapNode<T>* prev = NULL;                  // Prev Pointer to maintain the list if head is delete & thus forming link with head->next

        while(head != NULL)
        {
            if(head->key == key)
            {
                if(prev == NULL)             // If the First Node is to be delete so head should be head->next
                {
                    bucket[BucketIndex] = head->next;
                }
                else{
                    prev->next = head->next;         // If any other node from middle
                }

                T value = head->value;
                head->next = NULL;           // Done so that if we delete this head so it would not effect other nodes
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }

        return 0;
    }

    // To Search for a Particular key in HashMap
    T getValue(string key)
    {
        int BucketIndex = getBucketIndex(key);
        MapNode<T>* head = bucket[BucketIndex];
        
        while(head != NULL)
        {
            if(head->key == key)
            {
                return head->value;
            }

            head = head->next;
        }

        return 0;
    }

    ~HashMap()
    {
        for (int i = 0; i < NumSize; i++)
        {
            delete bucket[i];
        }

        delete[] bucket;
    }
};

int main()
{
    HashMap<int> hp;

    hp.insert("Sachin",18);
    hp.insert("Anjali",14);
    hp.insert("Sushma",42);
    hp.insert("Chandev",46);
    hp.insert("Deep",26);
    hp.insert("Rahul",4);
    hp.insert("Chings",33);
    hp.insert("GamerBoy",19);
    hp.insert("priya",20);

    cout<<"Size of HashMap "<<hp.getSize()<<endl;

    cout<<"Sushma has Value : "<<hp.getValue("Sushma")<<endl;

    cout<<hp.deletion("priya")<<endl;
    cout<<hp.deletion("Rahul")<<endl;

    cout<<"Size of Hashmap : "<<hp.getSize()<<endl;

    return 0;
}