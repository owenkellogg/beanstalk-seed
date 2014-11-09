#include "beanstalk.hpp"
#include <iostream>
#include <assert.h>

using namespace std;
using namespace Beanstalk;

int main(int argc, char* argv[]) {

    string message;

    if (argv[1]) {
      message = argv[1];
    } else {
      message = "hello beanstalkd";
    }

    Client client("127.0.0.1", 11300);
    assert(client.use("test"));
    assert(client.watch("test"));
  
    int id = client.put(message);
}
