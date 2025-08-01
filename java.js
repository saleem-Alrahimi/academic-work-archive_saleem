// script.js

// وظيفة لجمع المعلومات وعرضها في وحدة التحكم
function submitForm() {
    // الحصول على القيم من الحقول
    const firstName = document.querySelector('input[name="name"]').value || 'غير متوفر';
    const fatherName = document.querySelector('input[name="namescan"]').value || 'غير متوفر';
    const grandfatherName = document.querySelector('input[name="nametwescan"]').value || 'غير متوفر';
    const lastName = document.querySelector('input[name="lastname"]').value || 'غير متوفر';
    const idType = document.querySelector('input[name="cart"]:checked') ? document.querySelector('input[name="cart"]:checked').value : 'غير متوفر';
    const idNumber = document.querySelector('input[name="namecard"]').value || 'غير متوفر';
    const gender = document.querySelector('input[name="sex"]:checked') ? document.querySelector('input[name="sex"]:checked').value : 'غير متوفر';
    const issueDate = document.querySelector('input[name="date"]').value || 'غير متوفر';
    const postalCode = document.querySelector('input[name="hhhh"]').value || 'غير متوفر';
    const nationality = document.querySelector('select[name="nationality"]').value || 'غير متوفر';
    const city = document.querySelector('select[name="city"]').value || 'غير متوفر';

    // عرض القيم في وحدة التحكم
    console.log(`الاسم الأول: ${firstName}`);
    console.log(`اسم الأب: ${fatherName}`);
    console.log(`اسم الجد: ${grandfatherName}`);
    console.log(`اسم العائلة: ${lastName}`);
    console.log(`نوع الهوية: ${idType}`);
    console.log(`رقم الهوية: ${idNumber}`);
    console.log(`الجنس: ${gender}`);
    console.log(`تاريخ الإصدار: ${issueDate}`);
    console.log(`الرمز البريدي: ${postalCode}`);
    console.log(`الجنسية: ${nationality}`);
    console.log(`المدينة: ${city}`);
}

// إضافة حدث الضغط على زر الإرسال
document.addEventListener('DOMContentLoaded', () => {
    const nextButton =document.getElementById('next'); // تأكد من وجود زر إرسال في النموذج
    if (nextButton) {
        nextButton.onclick = function(event) {
            event.preventDefault(); // منع الإرسال الفوري للنموذج
            submitForm(); // استدعاء الوظيفة لجمع البيانات وعرضها
             // الانتقال بعد فترة قصيرة
             setTimeout(() => {
                window.location.href = nextButton.href; // الانتقال إلى الصفحة التالية
            }, 3000); // الانتقال بعد 1 ثانية
        };
    }
});
