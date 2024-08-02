#include "awry/awry.h"

describe("less than or equal to assertion", test_gte_assertion)
  it("can check if less than")
    expect(0) to be less_than_or_equal_to(1)
  end

  it("can check if equal to")
    expect(1) to be less_than_or_equal_to(1)
  end

  it("can check if not less than or equal to")
    expect(2) to not be less_than_or_equal_to(1)
  end
end

int main(void) {
  Awry.run();
  Awry.clear(&Awry);
  return 0;
}