//
//  CTXMAMCodeCoverageFailTests.swift
//  CTXMAMCodeCoverageFailTests
//
//  Created by Gero Herkenrath on 12.06.24.
//

import XCTest
@testable import CTXMAMCodeCoverageFail

final class CTXMAMCodeCoverageFailTests: XCTestCase {

    func test_ViewController_functionToTest_properlyAdds() {
        let underTest = ViewController()
        XCTAssertEqual(underTest.functionToTest(x: 2, y: 3), 5)
    }
}
