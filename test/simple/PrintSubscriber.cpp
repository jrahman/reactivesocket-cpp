#include "PrintSubscriber.h"
#include <folly/Memory.h>
#include <folly/io/IOBufQueue.h>
#include <iostream>

namespace reactivesocket {
void PrintSubscriber::onSubscribe(Subscription& subscription) {
  subscription.request(std::numeric_limits<uint32_t>::max());
}

void PrintSubscriber::onNext(Payload element) {
  std::cout << "PrintSubscriber.onNext " << element->moveToFbString() << "\n";
}

void PrintSubscriber::onComplete() {
  std::cout << "PrintSubscriber.onComplete\n";
}

void PrintSubscriber::onError(folly::exception_wrapper ex) {
  std::cout << "PrintSubscriber.onError " << ex.what() << "\n";
}
}
