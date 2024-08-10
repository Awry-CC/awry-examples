#include "awry/awry.h"

describe("when construct", test_when_construct)
  when("a when construct is called")
    it("is defined")
      expect(WHEN_TYPE) to equal(0x06)
    end
  end
end

int main(void) {
  Awry.run();
  Awry.clear(&Awry);
  return 0;
}