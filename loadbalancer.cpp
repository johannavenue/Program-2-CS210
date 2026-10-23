/* loadbalancer.cpp
 *
 * Manage the CPU load by assigning next job to CPU with the least load
 */

#include "loadbalancer.h"
#include <stdexcept>

int loadbalancer::getTime()
{
   return systemTime;
}

void loadbalancer::incTime()
{
   systemTime ++;

}
  
void loadbalancer::addRequest(request r)
{
   requestQueue.push(r);
   incTime();
 

}
  
request loadbalancer::getRequest()
{
   incTime();
   if (requestQueue.empty()) {
      throw std::out_of_range("Cannot get a request from an empty request queue");
   }

   request r = requestQueue.front();
   requestQueue.pop();
   return r;
}

bool loadbalancer::isRequestQueueEmpty()
{
   return requestQueue.empty();
  
} 

int loadbalancer::getSize()
{
   return requestQueue.size(); 
  
} 
