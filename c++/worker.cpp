#include "beanstalk.hpp"
#include <iostream>
#include <assert.h>

using namespace std;
using namespace Beanstalk;

int main() {
    Client client("127.0.0.1", 11300);
    assert(client.use("test"));
    assert(client.watch("test"));

    Job job;

    for (;;) {

      assert(client.reserve(job) && job);

      cout << "reserved job id: "
           << job.id()
           << " with body {" << job.body() << "}"
           << endl;

      assert(client.del(job.id()));
      cout << "deleted job id: " << job.id() << endl;
    }
}
