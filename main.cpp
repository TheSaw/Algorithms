#include <iostream>
#include <vector>
#include <string>

#include "select.h"
#include "sort.h"
#include "utils.h"
#include "timer.h"
#include "list.h"
#include "hashtable.h"

int main()
{
	Timer t;

	hashtable<std::string> H;
	H.put("magyari", "Attila");
    H.remove("magyari");
    H.put("magyari", "Attilai");
    H.put("magya", "Attilari");
    H.put("magya", "Attilaari");

    std::string s = H.get("magya");
    H.remove("magyari");
  
}
