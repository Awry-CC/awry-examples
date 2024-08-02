#include "awry/awry.h"

describe("less than assertion", test_lt_assertion)
  it("can check if less than")
    expect(0) to be less_than(1)
  end

  it("can check if not less than")
    expect(2) to not be less_than(1)
  end
end

int main(void) {
  Awry.run();
  Awry.clear(&Awry);
  return 0;
}