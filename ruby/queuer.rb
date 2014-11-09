require 'beaneater'
require 'json'

# Connect to pool
@beanstalk = Beaneater::Pool.new(['localhost:11300'])
# Enqueue jobs to tube
@tube = @beanstalk.tubes["my-tube"]
@tube.put '{ "key" : "foo" }', :pri => 5
@tube.put '{ "key" : "bar" }', :delay => 3
# Process jobs from tube
