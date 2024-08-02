#include "awry/awry.h"

describe("be_false assertion", test_be_false_assertion)
  it("can check if false")
    expect(0) to be_false
  end

  it("can check if not false")
    expect(1) to not be_false
  end
end

int main(void) {
  Awry.run();
  Awry.clear(&Awry);
  return 0;
}