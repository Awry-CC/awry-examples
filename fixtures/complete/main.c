#include <stdlib.h>
#include "awry/awry.h"

typedef struct PersonStruct {
  int age;
  char *name;
} Person;

Person* personConstructor(char* name, int age) {
  Person *newPerson = malloc(sizeof(Person));
  newPerson->name = malloc(strlen(name) + 1);
  strcpy(newPerson->name, name);
  newPerson->age = age;

  return newPerson;
}

define_fixture(before, before_all) {
  // this fixture will run first
  *subject = personConstructor("Fry", 3000);
}

define_fixture(before, before_change_age) {
  // this fixture will run second
  Person *p = *subject;
  p->age = 3001;
}

define_fixture(after, after_all) {
  // this fixture will run last
  Person *p = *subject;
  free(p->name);
  free(p);
}

define_fixture(after, after_change_age) {
  // this fixture will run first in the when("the the age is updated") block
  Person *p = *subject;
  p->age = 3000;
}

describe("all fixtures", test_all_fixtures)

  before(before_all)
  after(after_all)

  it("initializes the person for each test")
    Person *fry = subject();
    expect(fry->name) to equal("Fry")
  end

  when("the the age is updated")
    before(before_change_age)
    after(after_change_age)

    it("gets the right age")
      Person *fry = subject();
      expect(fry->age) to equal(3001)
    end
  end

  when("rechecking the age")
    it("has been restored to the original age")
      Person *fry = subject();
      expect(fry->age) to equal(3000)
    end
  end
end

int main(void) {
  Awry.run();
  Awry.clear(&Awry);
  return 0;
}