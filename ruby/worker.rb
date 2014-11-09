require 'beaneater'
require 'json'

@beanstalk = Beaneater::Pool.new(['localhost:11300'])
# Enqueue jobs to tube
@tube = @beanstalk.tubes["my-tube"]

while @tube.peek(:ready)
  job = @tube.reserve
  puts "job value is #{JSON.parse(job.body)["key"]}!"
  job.delete
end
# Disconnect the pool
@beanstalk.close
