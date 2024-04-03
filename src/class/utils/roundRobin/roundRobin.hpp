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
        ~roundRobin()= default;

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
            buf.push_back(buf.front());
            buf.erase(buf.begin());
            return buf.front();
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
            buf.clear();
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

        /**
         * @brief assignment operator
         *
         * @param rhs vector<t> that will be assigned
         *
         * @return roundRobin<T>&
        */
        roundRobin<T>& operator= (const std::vector<T>& rhs){
            this->buf = rhs;
            return *this;
        }

        vector<T> getBuffer() const {
            return buf;
        }

        typename std::vector<T>::iterator begin() {
            return buf.begin();
        }

        typename std::vector<T>::iterator end() {
            return buf.end();
        }

        //iterator for roundRobin
        class iterator{
            private:
                typename std::vector<T>::iterator it;
                typename std::vector<T>::iterator begin;
                typename std::vector<T>::iterator end;
            public:
                iterator(typename std::vector<T>::iterator it, typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end){
                    this->it = it;
                    this->begin = begin;
                    this->end = end;
                }

                iterator& operator++(){
                    it++;
                    if (it == end){
                        it = begin;
                    }
                    return *this;
                }

                iterator operator++(int){
                    iterator temp = *this;
                    it++;
                    if (it == end){
                        it = begin;
                    }
                    return temp;
                }

                T& operator*(){
                    return *it;
                }

                bool operator==(const iterator& rhs){
                    return it == rhs.it;
                }

                bool operator!=(const iterator& rhs){
                    return it != rhs.it;
                }
        };
};


#endif // ROUND_ROBIN_HPP_