Rails.application.routes.draw do

  mount BeanstalkdView::Server, :at => "/beanstalkd"

end
