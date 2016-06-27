//===- J2.cpp -------------------------------------------------------------===//
//
//                             The LLVM Linker
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// J2 linker support.
//===----------------------------------------------------------------------===//

#include "InputFiles.h"
#include "Symbols.h"
#include "Target.h"
#include "llvm/Object/ELF.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/Endian.h"

using namespace llvm;
using namespace llvm::object;
using namespace llvm::support::endian;
using namespace llvm::ELF;
using namespace lld;
using namespace lld::elf;

namespace {
class J2 final : public TargetInfo {
public:
  void relocateOne(uint8_t *Loc, RelType Type, uint64_t Val) const override;
  RelExpr getRelExpr(RelType Type, const Symbol &S,
                     const uint8_t *Loc) const override;
};
} // namespace

void J2::relocateOne(uint8_t *Loc, uint32_t Type, uint64_t Val) const {
  switch (Type) {
  default:
    error(getErrorLocation(Loc) + "unrecognized reloc " + Twine(Type));
    break;
  }
}

RelExpr J2::getRelExpr(RelType Type, const Symbol &S,
                       const uint8_t *Loc) const {
  switch (Type) {
  default:
    error(getErrorLocation(Loc) + ": unknown relocation type: " + Twine(Type));
    return {};
  }
}

TargetInfo *elf::getJ2TargetInfo() {
  static J2 Target;
  return &Target;
}
