#include "awry/awry.h"

describe("describe construct", test_describe_construct)
  it("creates a non-null function reference")
    expect((void*)test_describe_construct) to not be_null
  end

  it("defines the function")
    expect((void*)test_describe_construct) to equal((void*)test_describe_construct)
  end
end

int main(void) {
  Awry.run();
  Awry.clear(&Awry);
  return 0;
}