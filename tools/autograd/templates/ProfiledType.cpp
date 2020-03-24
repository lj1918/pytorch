#include "torch/csrc/autograd/VariableTypeUtils.h"

#include <ATen/TypeDefault.h>
#include <ATen/core/op_registration/op_registration.h>

#include "torch/csrc/autograd/function.h"

// ${generated_comment}

// NOTE [Sharded File]: on this file's split-into-shards state
//
// Back in the good old days, VariableType.cpp was generated as one
// file with every function in it, and everything was great and
// simple.
//
// However, this file was also very large (over 36,000 lines), and
// compiling it was very slow, and in fact was a significant
// bottleneck for incremental rebuilds. To address this, we now
// generate the file split across multiple shards, named
// ProfiledType_0.cpp and so on, which can be compiled in parallel.
//
// For ease of inspection and debugging, so that it's not necessary to
// go rooting around in multiple files, we also generate all the
// functions together in ProfiledTypeEverything.cpp. This generated
// file is only for convenience; it's not actually used in the
// build. If the file you're looking at now is one of the shards, you
// may want to switch over to the Everything variant to make you
// grepping smoother.

using namespace at;
using namespace torch::autograd::generated;
using torch::autograd::Node;

namespace torch {

namespace ProfiledType {

struct AutoNonProfileTypeMode {
  AutoNonProfileTypeMode() {
    orig_state = c10::impl::tls_is_dispatch_key_included(c10::DispatchKey::Profiler);
    c10::impl::tls_set_dispatch_key_included(c10::DispatchKey::Profiler, false);
  }
  ~AutoNonProfileTypeMode() {
    c10::impl::tls_set_dispatch_key_included(c10::DispatchKey::Profiler, orig_state);
  }
  bool orig_state;
};

namespace {
${profiled_method_definitions}
}  // namespace
}  // namespace ProfiledType

namespace {

auto registerer = torch::RegisterOperators()
  ${profiled_wrapper_registrations};

}  // namespace

} // namespace torch
