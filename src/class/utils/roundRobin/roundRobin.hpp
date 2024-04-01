#ifndef ROUND_ROBIN_HPP_
#define ROUND_ROBIN_HPP_

#include <vector>
#include <iostream>

template <class T>
class roundRobin{
    private:
        std::vector<T> buf;
    public:
        /**
         * @brief Construct a new round Robin object
        */
        roundRobin(){
            buf = std::vector<T>();
        }
        /**
         * @brief Add a new element to the vector
         * 
         * @param elem 
         */
        ~roundRobin(){}


        /**
         * @brief Get the first element
         * 
         * @return T 
         */
        T top(){
            return buf.front();
        }

        /**
         * @brief Move first element into last
         * @return first element
        */
        T next(){
            T temp = buf.front();
            buf.push_back(temp);
            buf.erase(buf.begin());
            return temp;
        }

        /**
         * @brief Add a new element into last element
         * 
         * @param elem 
        */
        void add(T elem){
            buf.push_back(elem);
        }

        /**
         * @brief Find index of element
         * 
         * @param elem
         * 
         * @return index of element if found, -1 if not found
        */
        int findIdx(T elem){
            std::vector<T> temp = buf;
            int idx = 0;
            while(!temp.empty()){
                if(temp.front() == elem){
                    return idx;
                }
                temp.erase(temp.begin());
                idx++;
            }
            return -1;
        }

        /**
         * @brief Get the size of vector
         * 
         * @return int 
        */
        int size(){
            return buf.size();
        }

        /**
         * @brief Check if vector is empty
         * 
         * @return true if empty, false if not
        */
        bool isEmpty(){
            return buf.empty();
        }

        /**
         * @brief Clear the vector
        */
        void clear(){
            while(!buf.empty()){
                buf.pop();
            }
        }

        /**
         * @brief Print the vector
        */
        friend std::ostream& operator << (std::ostream& os, roundRobin<T>& r){
        int size = r.buf.size();
        os << "(";
        for (int i = 0; i < size; i++){
            os << r.buf.front();
            if (i != size - 1) os << ", ";
            r.next();
        }
        os << ")" << std::endl;
        return os;
    }

};

#endif // ROUND_ROBIN_HPP_