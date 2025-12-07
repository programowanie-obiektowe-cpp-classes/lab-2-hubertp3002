#pragma once

#include "Resource.hpp"

class ResourceManager
{
   


 public:

    ResourceManager() : R{} 
    { 
        R = new Resource();

    }




     ResourceManager(const ResourceManager& n) : R{} 
     { R = new Resource(*n.R);
     
     }

     ResourceManager& operator=(const ResourceManager& n)
     {
             delete R;
             R = new Resource(*n.R);


         return *this;
     }

    ~ResourceManager() {
    
    delete R;
    
    }

    ResourceManager(ResourceManager&& other) noexcept : R(other.R) { other.R = nullptr; }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            delete R;
            R       = other.R;
            other.R = nullptr;
        }
        return *this;
    }


    double get()
    {
    
        return R->get();
    }

    Resource* R;
};
